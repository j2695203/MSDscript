/**
* \file cmdline.cpp
* \brief contains cmdline class definition
*
* execution for each command line argument
* \author Jinny
*/
#define CATCH_CONFIG_RUNNER

#include "cmdline.hpp"


run_mode_t use_arguments(int argc, const char * argv[]){
    
    bool isTested = false;
    
    for(int i = 1; i < argc; i++ ){
        
        if( strcmp(argv[i], "--help") == 0 ){
            std::cout << "Accepted arguments: --test --help \n";
            exit(0);
            
        }else if( strcmp(argv[i], "--test") == 0 && !isTested ){
            isTested = true;
            if( Catch::Session().run(1, argv) != 0){
                exit(1);
            }
            
        }else if ( strcmp(argv[i], "--test") == 0 && isTested ){
            std::cerr << "Error: Already tested. \n";
            exit(1);
            
        }else if ( strcmp(argv[i], "--interp") == 0 ){
            return do_interp;
            
        }else if( strcmp(argv[i], "--print") == 0 ){
            return do_print;
            
        }else if( strcmp(argv[i], "--pretty-print") == 0 ){
            return do_pretty_print;
            
        }else if( strcmp(argv[i], "--pretty-print") == 0 ){
            return do_pretty_print;
            
        }else{
            std::cerr << "Error: Not an accepted argument. \n";
            exit(1);
        }
    }
    return do_nothing;
}
