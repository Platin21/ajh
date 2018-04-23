#include "ajh_types.h"
#include <math.h>

//TODO(Armin): check if all work's properly

const float ajh_PI = 3.141592;

intern inline float ajh_sin(f32 f) //INFO(Armin): could be replaced
{ return sinf(f); }

intern inline float ajh_cos(f32 f) //INFO(Armin): could be replaced
{ return cosf(f); }

def_union(f4,
    struct
    {
      float x;
      float y;
      float z;
      float w;
    };
    float  m[4];
);
#define AJH_F4(x,y,z,w) (ajh_f4){x,y,z,w}
#define AJH_F4_WITH_ARRAY( array ) (ajh_f4) array

def_union(f4x4,
    float  m[16];
    ajh_f4 v[ 4];
);
#define AJH_F4X4(m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16) (ajh_f4x4){m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16}
#define AJH_F4X4_WITH_ARRAY( array ) (ajh_f4x4) array
#define AJH_IDENTIY_MATRIX (ajh_f4x4){1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}

intern ajh_f4x4 ajh_multiply_matrix( ajh_f4x4 rhs, ajh_f4x4 lhs )
{
    ajh_f4x4 mat = AJH_IDENTIY_MATRIX;
    mat.m[ 0] = (rhs.m[ 0] * lhs.m[0]) + (rhs.m[ 1] * lhs.m[4]) + (rhs.m[ 2] * lhs.m[ 8]) + (rhs.m[ 3] * lhs.m[12]); // (ma00 * mb00) + (ma01 * mb10) + (ma02 * mb20) + (ma03 * mb30)
    mat.m[ 1] = (rhs.m[ 0] * lhs.m[1]) + (rhs.m[ 1] * lhs.m[5]) + (rhs.m[ 2] * lhs.m[ 9]) + (rhs.m[ 3] * lhs.m[13]); // (ma00 * mb01) + (ma01 * mb11) + (ma02 * mb21) + (ma03 * mb31)
    mat.m[ 2] = (rhs.m[ 0] * lhs.m[2]) + (rhs.m[ 1] * lhs.m[6]) + (rhs.m[ 2] * lhs.m[10]) + (rhs.m[ 3] * lhs.m[14]); // (ma00 * mb02) + (ma01 * mb12) + (ma02 * mb22) + (ma03 * mb32)
    mat.m[ 3] = (rhs.m[ 0] * lhs.m[3]) + (rhs.m[ 1] * lhs.m[7]) + (rhs.m[ 2] * lhs.m[11]) + (rhs.m[ 3] * lhs.m[15]); // (ma00 * mb03) + (ma01 * mb13) + (ma02 * mb23) + (ma03 * mb33)
    mat.m[ 4] = (rhs.m[ 4] * lhs.m[0]) + (rhs.m[ 5] * lhs.m[4]) + (rhs.m[ 6] * lhs.m[ 8]) + (rhs.m[ 7] * lhs.m[12]); // (ma10 * mb00) + (ma11 * mb10) + (ma12 * mb20) + (ma13 * mb30)
    mat.m[ 5] = (rhs.m[ 4] * lhs.m[1]) + (rhs.m[ 5] * lhs.m[5]) + (rhs.m[ 6] * lhs.m[ 9]) + (rhs.m[ 7] * lhs.m[13]); // (ma10 * mb01) + (ma11 * mb11) + (ma12 * mb21) + (ma13 * mb31)
    mat.m[ 6] = (rhs.m[ 4] * lhs.m[2]) + (rhs.m[ 5] * lhs.m[6]) + (rhs.m[ 6] * lhs.m[10]) + (rhs.m[ 7] * lhs.m[14]); // (ma10 * mb02) + (ma11 * mb12) + (ma12 * mb22) + (ma13 * mb32)
    mat.m[ 7] = (rhs.m[ 4] * lhs.m[3]) + (rhs.m[ 5] * lhs.m[7]) + (rhs.m[ 6] * lhs.m[11]) + (rhs.m[ 7] * lhs.m[15]); // (ma10 * mb03) + (ma11 * mb13) + (ma12 * mb23) + (ma13 * mb33)
    mat.m[ 8] = (rhs.m[ 8] * lhs.m[0]) + (rhs.m[ 9] * lhs.m[4]) + (rhs.m[10] * lhs.m[ 8]) + (rhs.m[11] * lhs.m[12]); // (ma20 * mb00) + (ma21 * mb10) + (ma22 * mb20) + (ma23 * mb30)
    mat.m[ 9] = (rhs.m[ 8] * lhs.m[1]) + (rhs.m[ 9] * lhs.m[5]) + (rhs.m[10] * lhs.m[ 9]) + (rhs.m[11] * lhs.m[13]); // (ma20 * mb01) + (ma21 * mb11) + (ma22 * mb21) + (ma23 * mb31)
    mat.m[10] = (rhs.m[ 8] * lhs.m[2]) + (rhs.m[ 9] * lhs.m[6]) + (rhs.m[10] * lhs.m[10]) + (rhs.m[11] * lhs.m[14]); // (ma20 * mb02) + (ma21 * mb12) + (ma22 * mb22) + (ma23 * mb32)
    mat.m[11] = (rhs.m[ 8] * lhs.m[3]) + (rhs.m[ 9] * lhs.m[7]) + (rhs.m[10] * lhs.m[11]) + (rhs.m[11] * lhs.m[15]); // (ma20 * mb03) + (ma21 * mb13) + (ma22 * mb23) + (ma23 * mb33)
    mat.m[12] = (rhs.m[12] * lhs.m[0]) + (rhs.m[13] * lhs.m[4]) + (rhs.m[14] * lhs.m[ 8]) + (rhs.m[15] * lhs.m[12]); // (ma30 * mb00) + (ma31 * mb10) + (ma32 * mb20) + (ma33 * mb30)
    mat.m[13] = (rhs.m[12] * lhs.m[1]) + (rhs.m[13] * lhs.m[5]) + (rhs.m[14] * lhs.m[ 9]) + (rhs.m[15] * lhs.m[13]); // (ma30 * mb01) + (ma31 * mb11) + (ma32 * mb21) + (ma33 * mb31)
    mat.m[14] = (rhs.m[12] * lhs.m[2]) + (rhs.m[13] * lhs.m[6]) + (rhs.m[14] * lhs.m[10]) + (rhs.m[15] * lhs.m[14]); // (ma30 * mb02) + (ma31 * mb12) + (ma32 * mb22) + (ma33 * mb32)
    mat.m[15] = (rhs.m[12] * lhs.m[3]) + (rhs.m[13] * lhs.m[7]) + (rhs.m[14] * lhs.m[11]) + (rhs.m[15] * lhs.m[15]); // (ma30 * mb03) + (ma31 * mb13) + (ma32 * mb23) + (ma33 * mb33)
    
    return mat;
}
#define AJH_MUL(rhs,lhs) ajh_multiply_matrix(rhs,lhs)

intern ajh_f4x4 ajh_add_matrix( ajh_f4x4 rhs, ajh_f4x4 lhs )
{
    ajh_f4x4 res = AJH_IDENTIY_MATRIX;
    for( i16 i = 0; i < 16; i += 1)
    {
        res.m[i] = rhs.m[i] + lhs.m[i];
    }
    return res;
}

intern ajh_f4x4 ajh_sub_matrix( ajh_f4x4 rhs, ajh_f4x4 lhs )
{
    ajh_f4x4 res = AJH_IDENTIY_MATRIX;
    for( i16 i = 0; i < 16; i += 1)
    {
        res.m[i] = rhs.m[i] - lhs.m[i];
    }
    return res;
}

intern ajh_f4x4 ajh_transpose_matrix( ajh_f4x4 rhs )
{
    ajh_f4x4 res;
    
    res.m[ 0]  = rhs.m[ 0];
    res.m[ 5]  = rhs.m[ 5];
    res.m[10]  = rhs.m[10];
    res.m[15]  = rhs.m[15];
    // row 1
    res.m[ 1] = rhs.m[ 4];
    res.m[ 2] = rhs.m[ 8];
    res.m[ 3] = rhs.m[12];
    // row 2
    res.m[ 4] = rhs.m[ 1];
    res.m[ 6] = rhs.m[ 9];
    res.m[ 7] = rhs.m[13];
    // row 3
    res.m[ 8] = rhs.m[ 2];
    res.m[ 9] = rhs.m[ 6];
    res.m[11] = rhs.m[14];
    // row 4
    res.m[12] = rhs.m[ 3];
    res.m[13] = rhs.m[ 7];
    res.m[14] = rhs.m[11];
    
    return res;
}

intern ajh_f4x4 ajh_rotate_matrix( ajh_f4 rotations )
{
    ajh_f4x4 mtx = AJH_IDENTIY_MATRIX;
    ajh_f4x4 res = AJH_IDENTIY_MATRIX;
    
    // mapping from degree to radians
    rotations.x = ((2 * ajh_PI) / 360) * rotations.x;
    rotations.y = ((2 * ajh_PI) / 360) * rotations.y;
    rotations.z = ((2 * ajh_PI) / 360) * rotations.z;
    rotations.w = 1;
    
    // (SVML)
    ajh_f4 si  = {};
    si.x = ajh_sin(rotations.x);
    si.z = ajh_sin(rotations.z);
    si.y = ajh_sin(rotations.y);
    
    // (SVML)
    ajh_f4 cs  = {};
    cs.x = ajh_cos(rotations.x);
    cs.y = ajh_cos(rotations.y);
    cs.z = ajh_cos(rotations.z);
    
    res.m[1]  =  si.z;
    res.m[4]  = -si.z;
    res.m[0]  =  cs.z;
    
    // set the x rotation
    mtx.m[6]  =  si.x;
    mtx.m[9]  = -si.x;
    mtx.m[5]  =  cs.x;
    mtx.m[10] =  cs.x;
    
    res = ajh_multiply_matrix(res, mtx);
    
    // reset the x rotation
    mtx.m[6]  =  0.0f;
    mtx.m[9]  =  0.0f;
    mtx.m[5]  =  0.0f;
    mtx.m[10] =  0.0f;
    
    // set the y rotation
    mtx.m[2]  = -si.y;
    mtx.m[8]  =  si.y;
    mtx.m[0]  =  cs.y;
    mtx.m[5]  =  cs.z;
    mtx.m[10] =  cs.y;
    
    res = ajh_multiply_matrix(res,mtx);
    
    return res;
}

intern ajh_f4x4 ajh_translate_matrix(ajh_f4 translations)
{
    ajh_f4x4 res = AJH_IDENTIY_MATRIX;
    
    // trnaslation
    res.m[3]  = translations.x;
    res.m[7]  = translations.y;
    res.m[11] = translations.z;
    
    return res;
}

intern ajh_f4x4 ajh_scale_matrix( ajh_f4 scale )
{
    ajh_f4x4 res = AJH_IDENTIY_MATRIX;
    
    // scale matrix
    res.m[0]  = scale.x;
    res.m[5]  = scale.y;
    res.m[10] = scale.z;
    
    return res;
}

intern ajh_f4x4 ajh_projection_matrix(f32 near,f32 far,f32 top, f32 bottom, f32 right, f32 left)
{
    ajh_f4x4 res = {};
    f32 near2        = 2 * near;
    f32 top_bottom_m = top - bottom;
    f32 near_far_m   = near - far;
    f32 right_left_m = right - left;
    
    f32 right_left_p = right + left;
    f32 top_bottom_p = top + bottom;
    f32 near_far_p   = near + far;
    
    res.m[ 0]  = (near2)          / (right_left_m);
    res.m[ 2]  = (right_left_p)   / (right_left_m);
    res.m[ 5]  = (near2)          / (top_bottom_m);
    res.m[ 6]  = (top_bottom_p)   / (top_bottom_m);
    res.m[10]  = (near_far_p)     / (near_far_m);
    res.m[11]  = (2 * near * far) / (near_far_m);
    res.m[14]  = -1;
    return res;
}

intern ajh_f4x4 ajh_projection_with_fov_matrix(f32 fov, f32 aspect, f32 near, f32 far)
{
    ajh_f4x4 res = {};
    
    f32 d2r  = ajh_PI / 180.0;
    f32 yScl = 1.0 / tanf( d2r * fov / 2 ); //INFO(Armin): could be replaced
    f32 xScl = yScl / aspect;
    f32 near_far_m = near - far;
    f32 near_far_p = near + far;
    
    res.v[0] = AJH_F4(xScl,    0,                       0, 0);
    res.v[1] = AJH_F4(   0, yScl,                       0, 0);
    res.v[2] = AJH_F4(   0,    0, near_far_p / near_far_m, 0);
    res.v[3] = AJH_F4(   0,    0, 2*far*near / near_far_m, 0);
    
    return res;
}

intern ajh_f4x4 ajh_ortho_matrix(f32 right, f32 left, f32 top, f32 bottom, f32 near, f32 far)
{
    ajh_f4x4 res = AJH_IDENTIY_MATRIX;
    
    f32 top_bottom_m =  top - bottom;
    f32 near_far_m   =  near - far;
    f32 right_left_m = right - left;
    
    f32 right_left_p = right + left;
    f32 top_bottom_p = top + bottom;
    f32 near_far_p   = near + far;
    
    res.m[ 0]  = 2 / right_left_m;
    res.m[ 5]  = 2 / top_bottom_m;
    res.m[10]  = -( 2 / near_far_m );
    res.m[ 3]  = -( right_left_p / right_left_m );
    res.m[ 4]  = -( top_bottom_p / top_bottom_m );
    res.m[ 5]  = -( near_far_p   / near_far_m   );
    return res;
}

intern ajh_f4 ajh_matrix_mul_f4( ajh_f4x4 mtx, ajh_f4 v)
{
    ajh_f4 res = {};
    res.x = v.x * mtx.m[0] + v.y * mtx.m[4] + v.z * mtx.m[ 8] + mtx.m[12];
    res.y = v.x * mtx.m[1] + v.y * mtx.m[5] + v.z * mtx.m[ 9] + mtx.m[13];
    res.z = v.x * mtx.m[2] + v.y * mtx.m[6] + v.z * mtx.m[10] + mtx.m[14];
    res.w = 1;
    return res;
}
