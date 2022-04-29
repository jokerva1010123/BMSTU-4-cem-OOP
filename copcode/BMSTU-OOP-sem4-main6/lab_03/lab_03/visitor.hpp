#ifndef VISITOR_H
#define VISITOR_H

class Model;
class Composite;
class Camera;

class Visitor
{
public:
    Visitor() = default;

    ~Visitor() = default;

    virtual void visit(const Model &m) = 0;
    virtual void visit(const Composite &c) = 0;
    virtual void visit(const Camera &c) = 0;
};

#endif // VISITOR_H
