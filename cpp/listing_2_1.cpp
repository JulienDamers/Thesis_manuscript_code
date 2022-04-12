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
    // analytic expression of the tube [x](.)_computer
    TFunction f("((sin(3*t)+cos(2*t))+[0,0.5])");
    //Creating the tube
    Tube x(time_domain,delta,f);
    // analytic expression of the trajectory x*(.)
    TFunction f_traj("((sin(3*t)+cos(2*t))+0.2)");
    //Creating the trajectory
    Trajectory x_star(time_domain,f_traj,delta);

    // Graphics

    beginDrawing();
    VIBesFigTube fig("my_first_tube_figure");
    fig.add_tube(&x,"x");
    fig.set_tube_color(&x, "black[black]");
    fig.add_trajectory(&x_star, "x_star");
    fig.set_trajectory_color(&x_star,"orange");
    fig.show();

}

