#include "MyPipeline.hpp"


#include <algorithm>
#include <cctype>

int main()
{
    try {
        std::cout << std::endl << "===== DEMONSTRATION OF WORK =====" << std::endl << std::endl;
        

        std::cout << "Demonstration MyPipeline<int>" << std::endl;
        MyPipeline<int> pipeline;
        // adding steps using lambda functions 
        pipeline.addStep( "add one", [](int x) { return x + 1; } );
        pipeline.addStep( "double", [](int x) { return x * 2; } );
        pipeline.addStep( "square", [](int x) { return x * x; } );

        std::cout << pipeline << std::endl;
        std::cout << pipeline.run(29) << std::endl;
        for (int x : pipeline.trace(29)) {
            std::cout << x << " ";
        }
        std::cout << std::endl << std::endl;


        std::cout << "Demonstration MyPipeline<std::string>" << std::endl;
        MyPipeline<std::string> pipeline_s;
        pipeline_s.addStep( "add exclamition", [](std::string s) { return s + "!"; } );
        pipeline_s.addStep( "to upper", [](std::string s) { 
            std::transform(s.begin(), s.end(), s.begin(), ::toupper);
            return s; 
        } );
        pipeline_s.addStep( "add let's", [](std::string s) { return "LET'S" + s; } );
        std::cout << pipeline_s.run("go") << std::endl << std::endl;


        std::cout << "Demonstrationn exceptions" << std::endl;
        pipeline.removeStep(100);
        // next exception in next block of try-catch
        //pipeline.addStep( "", [](int x) { return x + 1; } );
        
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }
    // other exception
    try {
        MyPipeline<int> pipeline;
        pipeline.addStep( "", [](int x) { return x + 1; } );
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }

    std::cout << std::endl;
    return 0;
}