//
// Created by julien-damers on 12/04/2022.
//

#include "codac.h"
#include "codac-capd.h" //CAPD module

using namespace codac;
using namespace vibes;

int main()
{

    Interval time_domain(0,5); // Integration time
    double h = 0.01; // Time step for the integration scheme
    IntervalVector x_0({{0,0.1},{2,2.1}}); // Initial condition
    Function f("x1","x2","(1; -x2)"); // Evolution function to integrate
    // Generating the output tube of the integration using CAPD
    TubeVector a_capd = CAPD_integrateODE(time_domain,f,x_0,h);


    // Graphics
    beginDrawing();
    IntervalVector frame({{0,5.5},{-0.2,2.5}});
    VIBesFigMap fig("Integration with CAPD");
    fig.add_tube(&a_capd,"a", 0, 1);
    fig.show();
    fig.draw_box(x_0,"r[]");
    fig.axis_limits(frame);

}

