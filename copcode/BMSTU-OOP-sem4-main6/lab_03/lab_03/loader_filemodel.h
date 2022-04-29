#ifndef LOADER_FILEMODEL_H
#define LOADER_FILEMODEL_H


#include "base_loadermodel.h"

class LoaderFileModel: public LoaderBaseModel
{
public:
    LoaderFileModel();

    explicit LoaderFileModel(std::shared_ptr<std::ifstream> &name);

    ~LoaderFileModel() override = default;

    std::shared_ptr<Object> load(std::shared_ptr<BuilderModel> b) override;


    void open(std::string &name) override;
    void close() override;

protected:
    std::shared_ptr<std::ifstream> file;
};

#endif // LOADER_FILEMODEL_H
