/*
 * Quaternion.h
 *
 *  Created on: Aug 11, 2014
 *      Author: jdiep
 */

#ifndef QUATERNION_H_
#define QUATERNION_H_
#include <math.h>

class Quaternion {
public:
	Quaternion();
	virtual ~Quaternion();

    float w;
    float x;
    float y;
    float z;

    Quaternion(float nw, float nx, float ny, float nz) {
        w = nw;
        x = nx;
        y = ny;
        z = nz;
    }

    Quaternion getProduct(Quaternion q) {
        // Quaternion multiplication is defined by:
        //     (Q1 * Q2).w = (w1w2 - x1x2 - y1y2 - z1z2)
        //     (Q1 * Q2).x = (w1x2 + x1w2 + y1z2 - z1y2)
        //     (Q1 * Q2).y = (w1y2 - x1z2 + y1w2 + z1x2)
        //     (Q1 * Q2).z = (w1z2 + x1y2 - y1x2 + z1w2
        return Quaternion(
            w*q.w - x*q.x - y*q.y - z*q.z,  // new w
            w*q.x + x*q.w + y*q.z - z*q.y,  // new x
            w*q.y - x*q.z + y*q.w + z*q.x,  // new y
            w*q.z + x*q.y - y*q.x + z*q.w); // new z
    }

    float getMagnitude() {
            return sqrt(w*w + x*x + y*y + z*z);
    }

    Quaternion getConjugate() {
        return Quaternion(w, -x, -y, -z);
    }

    void normalize() {
        float m = getMagnitude();
        w /= m;
        x /= m;
        y /= m;
        z /= m;
    }

    Quaternion getNormalized() {
        Quaternion r(w, x, y, z);
        r.normalize();
        return r;
    }

};

#endif /* QUATERNION_H_ */
