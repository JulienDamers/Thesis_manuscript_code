//
// Created by julien-damers on 12/04/2022.
//

#include "codac.h"

using namespace codac;
using namespace vibes;

int main()
{
    Interval time_domain(0,5); // Integration time
    double h = 0.01; // Time step for the integration scheme
    IntervalVector x_0({{0,0.1},{2,2.1}}); // Initial condition
    Function f("x1","x2","(1; -x2)"); // Evolution function to integrate
    /*
    * Creation of a default tube: tube(time domain, time step, nb of dimensions)
    * For each dimension [a][i](.)(t)= [-inf,inf]
    */
    TubeVector a_Lohner(time_domain,h,2);
    // Creation of the Lohner contractor for the system defined by f
    CtcLohner c_Lohner(f);
    // Setting the initial condition: a.set(box, time)
    a_Lohner.set(x_0,0.);
    // Performing the integration
    c_Lohner.contract(a_Lohner);


    // Graphics
    beginDrawing();
    IntervalVector frame({{0,5.5},{-0.2,2.5}});
    VIBesFigMap fig("Integration with Löhner");
    fig.add_tube(&a_Lohner,"a", 0, 1);
    fig.show();
    fig.draw_box(x_0,"r[]");
    fig.axis_limits(frame);

}



