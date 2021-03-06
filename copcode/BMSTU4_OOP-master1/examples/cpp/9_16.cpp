// Пример 16. Стратегия (Strategy).
# include <iostream>
# include <memory>
# include <vector>

using namespace std;

class Strategy
{
public:
	virtual ~Strategy() = 0;

	virtual void algorithm() = 0;
};

Strategy::~Strategy() = default;

class ConStrategy1 : public Strategy
{
public:
	virtual void algorithm() override { cout << "Algorithm 1;" << endl; }
};

class ConStrategy2 : public Strategy
{
public:
	virtual void algorithm() override { cout << "Algorithm 2;" << endl; }
};

class Context
{
private:
	unique_ptr<Strategy> strategy;

public:
	explicit Context(Strategy* ptr) : strategy(ptr) {}

	void algorithmStrategy() { strategy->algorithm(); }
};

int main()
{
	Context obj(new ConStrategy2());

	obj.algorithmStrategy();
}
