#ifndef CAMERA_COMMAND_H
#define CAMERA_COMMAND_H

#include <memory>
#include <cstddef>

#include "base_command.h"

class BaseCameraCommand : public BaseCommand {};

class AddCamera : public BaseCameraCommand {
public:
    AddCamera(const double x,
              const double y,
              const double z);

    AddCamera() = delete;

    ~AddCamera() override = default;

    void execute() override;

private:
    double x_pos;
    double y_pos;
    double z_pos;
};

class RemoveCamera : public BaseCameraCommand {
public:
    explicit RemoveCamera(const size_t &camera_n);

    RemoveCamera() = delete;

    ~RemoveCamera() override = default;

    void execute() override;

private:
    size_t camera_n;
};

class MoveCamera : public BaseCameraCommand {
public:
    MoveCamera(const size_t &camera_n,
               const double &shift_x,
               const double &shift_y);

    MoveCamera() = delete;

    ~MoveCamera() override = default;

    void execute() override;

private:
    size_t camera_n;

    double shift_x;
    double shift_y;
};

class SetCamera : public BaseCameraCommand {
public:
    explicit SetCamera(const size_t &camera_n);

    SetCamera() = delete;

    ~SetCamera() override = default;

    void execute() override;


private:
    size_t camera_n;
};

class CountCamera : public BaseCameraCommand {
public:
    explicit CountCamera(std::shared_ptr<size_t> &c);

    CountCamera() = delete;

    ~ CountCamera() override = default;

    void execute() override;

private:
    std::shared_ptr<size_t> &count_;
};

#endif // CAMERA_COMMAND_H
