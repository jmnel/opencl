#include <CL/cl.h>
#include <CL/cl_platform.h>

#include <cstdlib>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

int main() {

    cl_uint num_of_platforms;
    auto error = clGetPlatformIDs( 0, nullptr, &num_of_platforms );

    if( error < 0 ) {
        cerr << "Unable to find any OpenGL platforms." << endl;
        exit( 1 );
    }

    cout << "Found " << num_of_platforms << " OpenGL platforms." << endl;

    cl_platform_id *platforms = new cl_platform_id[num_of_platforms];

    error = clGetPlatformIDs( num_of_platforms, platforms, nullptr );

    if( error < 0 ) {
        cerr << "Failed to get OpenCL platform ids." << endl;
        exit( 1 );
    }

    for( cl_uint i = 0; i < num_of_platforms; ++i ) {
        cout << i << ": " << platforms[i] << endl;

        const auto id = platforms[i];
        size_t param_size = 0;
        error = clGetPlatformInfo( id, CL_PLATFORM_PROFILE, 0,
                                   nullptr,
                                   &param_size );
        if( error < 0 ) {
            cerr << "Failed to get OpenCL platform ids." << endl;
            exit( 1 );
        }
        char *param_value = new char[1200];

        error = clGetPlatformInfo( id,
                                   CL_PLATFORM_EXTENSIONS,
                                   1200,
                                   param_value,
                                   nullptr );
        cout << param_size << endl;
        cout << error << endl;
        if( error < 0 ) {
            cerr << "Failed to get OpenCL pladsfasdftform ids." << endl;
            exit( 1 );
        }

        cout << param_value << endl;
    }

    return 0;
}
