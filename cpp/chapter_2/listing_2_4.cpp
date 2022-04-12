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
    TFunction fx("sin(t)+[-0.5,0.5]");
    TFunction fv("cos(t)");
    Tube x(time_domain,time_step,fx);
    Tube v(time_domain,time_step,fv);
    Tube x_save(x);

    Interval t(6,7);
    Interval z(0.8,1.5);
    CtcEval c_eval;

    IntervalVector t_z({t,z}); // save t and z before contraction

    c_eval.contract(t,z,x,v);

    beginDrawing();
    IntervalVector frame(IntervalVector({time_domain,{-2,2}}));



    VIBesFigTube fig_x("fig_x");
    fig_x.set_properties(0,0,600,300);
    fig_x.add_tube(&x_save,"x_before_contraction");
    fig_x.set_tube_color(&x_save,"black[black]");
    fig_x.add_tube(&x,"x_after_contraction");
    fig_x.set_tube_color(&x,"white[white]");

    fig_x.show();
    fig_x.axis_limits(frame);
    fig_x.draw_box(t_z,"r[]");


    t_z[0] = t;
    t_z[1] = z;
    fig_x.draw_box(t_z,"g[]");

}