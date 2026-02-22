#ifndef MyPipeline_hpp
#define MyPipeline_hpp


#include <string>
#include <vector>


 template <class T>
class MyPipeline
{
//  std::string name;

public:
    // Basic methods
    MyPipeline();
    size_t size() const;
    bool empty() const;
    void clear();

    // Adding step
    void addStep(const std::string& name, F func);
    // Remove step
    void removeStep(size_t index);
    // Run pipeline
    T run(T value) const;
    // Trace
    std::vector<T> trace(T value const);

    // Out <<
//  operator<<

};

#endif // MyPipeline_hpp