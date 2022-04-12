//
// Created by julien-damers on 12/04/2022.
//

#include "codac.h"

using namespace codac;
using namespace vibes;

int main()
{
    Interval time_domain(0,10);
    double time_step=0.0001;
    TFunction fx("t*[-0.5,0.5]");
    TFunction fv("[0.2,0.3]");
    Tube x(time_domain,time_step,fx);
    Tube v(time_domain,time_step,fv);

    CtcDeriv c_deriv;

    c_deriv.contract(x,v);

    beginDrawing();
    IntervalVector frame(IntervalVector({time_domain,{-5,5}}));

    VIBesFigTube fig_x("fig_x");
    fig_x.set_properties(0,0,600,300);
    fig_x.add_tube(&x,"x");
    fig_x.show();
    fig_x.axis_limits(frame);

}