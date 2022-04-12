//
// Created by julien-damers on 12/04/2022.
//

//
// Created by julien-damers on 12/04/2022.
//

#include "codac.h"

using namespace codac;

using namespace vibes; // For tube graphical display

int main()
{
    // Time domain on which the tube is defined
    Interval time_domain(0,6);
    // Time step used to create the tube or trajectory
    double delta = 0.1;
    // Creating the tube [x](.)
    TFunction fx("(sin(t)+[0,0.2])");
    Tube x(time_domain,delta,fx);
    // Creating the tube [y](.)
    TFunction fy("(t*[-0.2,0.2])");
    Tube y(time_domain,delta,fy);
    //Computing [z](.)
    Tube z = x+y;
    // Computing [d](.)
    Tube d = abs(y);




    // Graphics
    beginDrawing();

    IntervalVector frame({{0,4},{-2,2}});

    VIBesFigTube fig_x("fig_x");
    fig_x.set_properties(0,0,300,300);
    fig_x.add_tube(&x,"x");
    fig_x.show();
    fig_x.axis_limits(frame);

    VIBesFigTube fig_y("fig_y");
    fig_y.set_properties(400,0,300,300);
    fig_y.add_tube(&y,"y");
    fig_y.show();
    fig_y.axis_limits(frame);

    VIBesFigTube fig_d("fig_d");
    fig_d.set_properties(0,400,300,300);
    fig_d.add_tube(&d,"d");
    fig_d.show();
    fig_d.axis_limits(frame);

    VIBesFigTube fig_z("fig_z");
    fig_z.set_properties(400,400,300,300);
    fig_z.add_tube(&z,"z");
    fig_z.show();
    fig_z.axis_limits(frame);


}