#ifndef MODEL_COMMAND_H
#define MODEL_COMMAND_H

#include <memory>
#include <cstddef>

#include "base_command.h"
#include "object.h"

class BaseModelCommand: public BaseCommand
{};

class MoveModel: public BaseModelCommand
{
public:
    MoveModel(const double &dx,
              const double &dy,
              const double &dz, const size_t &n);

    MoveModel() = delete;

    ~MoveModel() override = default;

    void execute() override;

private:
    size_t model_n_;

    double dx, dy, dz;
};

class ScaleModel: public BaseModelCommand
{
public:
    ScaleModel(const double &x,
               const double &y,
               const double &z, const size_t &n);

    ScaleModel() = delete;

    ~ScaleModel() override = default;

    void execute() override;

private:
    size_t model_n_;

    double kx, ky, kz;
};

class RotateModel: public BaseModelCommand
{
public:
    RotateModel(const double &ox,
              const double &oy,
              const double &oz, const size_t &n);

    RotateModel() = delete;

    ~RotateModel() override = default;

    void execute() override;

private:
    size_t model_n_;

    double ox, oy, oz;
};

class ReformModel: public BaseModelCommand
{
public:
    ReformModel(const size_t &n,
                const Point &m,
                const Point &s,
                const Point &t);

    ReformModel() = delete;
    ~ReformModel() override = default;

    void execute() override;

private:
    size_t model_n_;

    Point move, scale, turn;
};


class LoadModel : public BaseModelCommand {
public:
    explicit LoadModel(std::string file_name);

     LoadModel() = delete;

    ~LoadModel() override = default;

    void execute() override;

private:
    std::string file_name;
};



class AddModel : public BaseModelCommand {
public:
    explicit AddModel(std::shared_ptr<Object> model);


    AddModel() = delete;
    ~AddModel() override = default;

    void execute() override;

private:
    std::shared_ptr<Object> model;
};


class RemoveModel : public BaseModelCommand {
public:
    RemoveModel() = delete;

    explicit RemoveModel(const size_t &model_n);

    ~RemoveModel() override = default;

    void execute() override;

private:
    size_t model_n_;
};

class ExportModel: public BaseModelCommand
{
public:
    ExportModel() = delete;

    explicit ExportModel(std::string filename);

    ~ExportModel() override = default;

    void execute() override;

private:
    std::string filename_;
};

class CountModel : public BaseModelCommand {
public:
    CountModel() = delete;

    explicit CountModel(std::shared_ptr<size_t> &c);



    ~CountModel() override = default;

    void execute() override;

private:
    std::shared_ptr<size_t> &count_;
};



#endif // MODEL_COMMAND_H
