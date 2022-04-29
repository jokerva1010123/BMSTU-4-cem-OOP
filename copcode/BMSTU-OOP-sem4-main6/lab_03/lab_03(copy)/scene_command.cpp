#include <utility>

#include "scene_command.h"
#include "load_scene_controller.h"
#include "loader_filescene.h"
#include "manager_draw_creator.h"
#include "manager_load_creator.h"
#include "manager_scene.h"
#include "manager_scene_creator.h"

DrawScene::DrawScene(std::shared_ptr<BaseDrawer> d)
    : drawer_(std::move(d))
{}

void DrawScene::execute()
{
    auto dm = DrawManagerCreator().create_man();
    auto sm = SceneManagerCreator().create_man();

    drawer_->clear_scene();
    dm->set_drawer(drawer_);
    dm->set_camera(sm->get_camera());
    sm->get_scene()->get_composite()->accept(dm);

}

LoadScene::LoadScene(std::string fn)
    : filename_(std::move(fn)) {}

void LoadScene::execute()
{
    auto m = LoadManagerCreator().create_man();
    std::shared_ptr<LoaderBaseScene> p(new LoaderFileScene);
    m->set_loader(std::shared_ptr<AbstractLoadController> (new LoadSceneController(p)));

    auto s = std::dynamic_pointer_cast<Scene>(m->load(filename_));

    SceneManagerCreator().create_man()->set_scene(s);
}
