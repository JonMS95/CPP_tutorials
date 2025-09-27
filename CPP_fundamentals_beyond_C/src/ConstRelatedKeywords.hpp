#ifndef CONST_RELATED_KEYWORDS
#define CONST_RELATED_KEYWORDS

constexpr int squareConstExpr(int x)
{
    return (x * x);
}

consteval int squareConstEval(const int x)
{
    return (x * x);
}

class ConstKeywordsDummyClass
{
private:
    mutable int counter = 0;
public:
    void incrementCounter(void) const;
    const int getCounter(void) const;
};

#endif