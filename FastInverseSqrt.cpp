#include <iostream>
#include <cmath>

// This only work if IEE754 fp is being used for default float
// Just for calculating log, 0.0683365F works for meeeeeeeee.
// author: ubussamad
int ffltest ()  { 
        float num  = 4.568;
        float stdlog = std::log2f( num );
        float nu =( (float) ( (*(unsigned int*)&num) ) )/ (float)(1<<23);
        float lg = ( nu ) + 0.0683365 - 127;
        std::cout << "Average diff is: " << std::abs(stdlog - lg) << std::endl;
        std::cout << "stdlog is: " << stdlog << "| mylog: " << lg << std::endl;
        return 0;
}

int fastFloatLog ( )  {

    float min_diff_chi = 0.0;
    float min_diff = 1.0;

    for ( float chi = 0.0F ; chi < 1.0F ; chi+=0.000001) {
        
        float avg_diff = 0.0;

        for ( float num = 0.1F ; num < 100.0 ; num+=0.5F ) {
        float stdlog = std::log2f( num );
        float nu =( (float) ( (*(unsigned int*)&num) ) )/ (float)(1<<23);
        float lg = ( nu ) + chi - 127;
        avg_diff += std::abs(stdlog - lg);

        }

        avg_diff /= 9900;
        // std::cout << "Avg diff: " << avg_diff << std::endl;
        if (avg_diff < min_diff) {min_diff = avg_diff;min_diff_chi = chi;}
    }

    std::cout << min_diff_chi << " | Min diff is: " << min_diff << std::endl;
    return 0;

}
