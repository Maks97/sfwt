#include <cmath>
#include "Vector.h"

const double GRAVITATIONAL_CONSTANT = 6.674e-11;

double findDistanceBetweenPoints(double aX, double aY, double bX, double bY)
{
    return std::sqrt(std::pow((bX - aX), 2) + std::pow((bY - aY), 2));
}

double findFoci(double semiMajorAxis, double semiMinorAxis)
{
    if (semiMinorAxis > semiMajorAxis)
    {
        double temp = semiMajorAxis;
        semiMajorAxis = semiMinorAxis;
        semiMinorAxis = temp;
    }
    return std::sqrt(std::pow(semiMajorAxis, 2) - std::pow(semiMinorAxis, 2));
}

// eccentricity = distance from the center to a focus Divided by the distance from that focus to a vertex
double findEccentricity(double semiMajorAxis, double semiMinorAxis)
{
    if(semiMajorAxis == semiMinorAxis)
        return 0; // Bail early if it's a circle
    else if(semiMinorAxis > semiMajorAxis)
    {
        double temp = semiMajorAxis;
        semiMajorAxis = semiMinorAxis;
        semiMinorAxis = temp;
    }
    double focus = findFoci(semiMajorAxis, semiMinorAxis);
    // Implicitly rotate the ellipse, this lets us compute the distance without messing with coordinates
    double vertexToFocus = findDistanceBetweenPoints(focus, 0, 0, semiMinorAxis);
    return focus / vertexToFocus;
}

double findOrbitalPeriod(double semiMajorAxis)
{
    //Tp=Te*(Rp/Re)^3/2
    //Te : Orbital period of Earth //31536000
    //Re : Mean distance between Earth and Sun //1.4960e11m
    //Tp : Orbital period of planet
    //Rp : Mean distance of Planet (Semi Major Axis)
    return 31536000 * std::pow((semiMajorAxis / 1.4960e11), 1.5);
}

double findSemiMinorAxis(double semiMajorAxis, double eccentricity){
    return semiMajorAxis * std::sqrt(1 - std::pow(eccentricity,2.0));
}

double findEllipseAndLineIntersection(double SemiMajorAxis, double eccentricity, double theta)
{

}
