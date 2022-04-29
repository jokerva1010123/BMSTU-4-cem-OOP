#ifndef LOADER_FILEMODEL_H
#define LOADER_FILEMODEL_H


#include "base_loadermodel.h"

class LoaderFileModel: public LoaderBaseModel
{
public:
    LoaderFileModel();

    explicit LoaderFileModel(std::shared_ptr<std::ifstream> &name);

    ~LoaderFileModel() override = default;

    std::vector<Point> load_points() override;
    std::vector<Link> load_links() override;


    void open(std::string &name) override;
    void close() override;

protected:
    std::shared_ptr<std::ifstream> file;
};

#endif // LOADER_FILEMODEL_H
