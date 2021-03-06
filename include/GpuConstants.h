/**
 * Header for variables stored in GPU constant memory
 * @file GpuConstants.h
 * @author Adam Koleszar (adam.koleszar@gmail.com) - implementation of functions used in the 2D solver
 * @author Alfonso Aguilar (a.aguilar-pontes@cranfield.ac.uk) - implementation of functions used in the 3D solver
 * @details These constants need to be extern in other files because they can only be declared in
 * one source file. If other object files need these variable, just include this header and don't
 * forget to compile them with -rdc=true
 *
 * Velocity unit vector components (#cx_d, #cy_d)
 * @verbatim
   (-1,1)   (0,1)   (1,1)
          6   2   5
            \ | /
  (-1,0) 3 -(0,0)- 1 (1,0)
            / | \
          7   4   8
   (-1,-1)  (0,-1)  (1,-1) @endverbatim
 * Lattice weights (#w_d)
 * @verbatim
    (1/36)   (1/9)   (1/36)
           6   2   5
             \ | /
    (1/9) 3 -(4/9)- 1 (1/9)
             / | \
           7   4   8
    (1/36)   (1/9)   (1/36) @endverbatim
 * Opposite lattices (#opp_d)
 * @verbatim
        (8)   (4)   (7)
           6   2   5
             \ | /
       (1) 3 -(0)- 1 (3)
             / | \
           7   4   8
        (5)   (2)   (6) @endverbatim
 */
#ifndef GPU_CONSTANTS_H
#define GPU_CONSTANTS_H

#ifndef RELEASE

extern  InletProfile inletProfile_d;     ///< inlet profile
extern  BoundaryType boundaryType_d;     ///< boundary type
extern  OutletProfile outletProfile_d;   ///< outlet profile
extern  FLOAT_TYPE rhoIn_d;              ///< input density
extern  FLOAT_TYPE uIn_d;                ///< input velocity x
extern  FLOAT_TYPE vIn_d;                ///< input velocity y
extern  int dlBoundaryId_d;              ///< boundary ID
extern  int depth_d;                     ///< number of rows Y
extern  int length_d;                    ///< number of columns X
extern  int height_d;                    ///< number of layers Z
extern  FLOAT_TYPE delta_d;              ///< grid spacing
extern  FLOAT_TYPE minInletCoordY_d;     ///< maximum inlet coordinate y
extern  FLOAT_TYPE maxInletCoordY_d;     ///< minimum inlet coordinate y
extern  FLOAT_TYPE minInletCoordZ_d;     ///< maximum inlet coordinate z
extern  FLOAT_TYPE maxInletCoordZ_d;     ///< minimum inlet coordinate z
extern  FLOAT_TYPE omega_d;            ///< collision frequency for D2Q9 \f$ \omega = \frac{1}{3\nu + 0.5} \f$
extern  FLOAT_TYPE omegaA_d;           ///< asymmetric collision frequency \f$ \omega_a = \frac{8(2-\omega)}{8-\omega} \f$
extern  FLOAT_TYPE g_d;
//#### 2D d2q9 ####//
extern  int cx2D_d[9];                   ///< velocity x unit vector components
extern  int cy2D_d[9];                   ///< velocity y unit vector components
extern  int c2D_d[9];                    ///< direction offset levels
extern  int opp2D_d[9];                  ///< opposite lattice offset
extern  FLOAT_TYPE w2D_d[9];             ///< lattice weights
extern  FLOAT_TYPE velMomMap2D_d[81];    ///< MRT constants: mapping between velocity and momentum space \f$ \mathbf{M} \f$
extern  FLOAT_TYPE momCollMtx2D_d[81];   ///< MRT constants: collision matrix in momentum space \f$ \mathbf{M}^{-1}\mathbf{S} \f$

//#### Color Gradient ####//
extern  FLOAT_TYPE beta_d;
extern  FLOAT_TYPE g_limit_d;
extern  FLOAT_TYPE r_alpha_d;
extern  FLOAT_TYPE b_alpha_d;
extern  FLOAT_TYPE bubble_radius_d;
extern  FLOAT_TYPE r_density_d;
extern  FLOAT_TYPE b_density_d;
extern  bool external_force_d;
extern  FLOAT_TYPE A_d;
extern  FLOAT_TYPE r_viscosity_d;
extern  FLOAT_TYPE b_viscosity_d;

//#### 2D Color Gradient ####//
extern  FLOAT_TYPE control_param_d;
extern  FLOAT_TYPE phi_d[9];
extern  FLOAT_TYPE teta_d[9];
extern  FLOAT_TYPE chi_d[9];
extern  FLOAT_TYPE psi_d[9];
extern  FLOAT_TYPE w_pert_d[9];
extern  FLOAT_TYPE c_norms_d[9];
extern  FLOAT_TYPE cg_w_d[9];
extern  FLOAT_TYPE hocg_w_d[25];
extern  int hocg_cx_d[25];
extern  int hocg_cy_d[25];

//#### 3D Color Gradient ####//
extern FLOAT_TYPE c_norms3D_d[19];
extern FLOAT_TYPE w_pert3D_d[19];
extern FLOAT_TYPE phi3D_d[19];
extern FLOAT_TYPE teta3D_d[19];
extern FLOAT_TYPE chi3D_d[19];
extern FLOAT_TYPE psi3D_d[19];
extern FLOAT_TYPE cg_w3D_d[19];
extern FLOAT_TYPE hocg_w3D_d[105];
extern int hocg_cx3D_d[105];
extern int hocg_cy3D_d[105];
extern int hocg_cz3D_d[105];
extern int hoc3D_d[105];

//#### 3D d3q19 ####//
extern FLOAT_TYPE wIn_d;
extern int cx3D_d[19];                   ///< velocity x unit vector components
extern int cy3D_d[19];                   ///< velocity y unit vector components
extern int cz3D_d[19];                   ///< velocity y unit vector components
extern int c3D_d[19];                    ///< direction offset levels
extern int opp3D_d[19];                  ///< opposite lattice offset
extern FLOAT_TYPE w3D_d[19];             ///< lattice weights
extern FLOAT_TYPE velMomMap3D_d[361];    ///< MRT constants: mapping between velocity and momentum space \f$ \mathbf{M} \f$
extern FLOAT_TYPE momCollMtx3D_d[361];   ///< MRT constants: collision matrix in momentum space \f$ \mathbf{M}^{-1}\mathbf{S} \f$

// Color Gradient
#pragma acc declare create(g_d, r_viscosity_d, b_viscosity_d, external_force_d, b_density_d, r_density_d, r_alpha_d, b_alpha_d, bubble_radius_d, g_limit_d, A_d, control_param_d, beta_d, minInletCoordY_d, maxInletCoordY_d, vIn_d, uIn_d, rhoIn_d, inletProfile_d, delta_d, length_d, depth_d, dlBoundaryId_d, boundaryType_d,outletProfile_d, omega_d, omegaA_d) 
// 2D
#pragma acc declare create(c_norms_d, velMomMap2D_d, momCollMtx2D_d, c2D_d, cx2D_d, cy2D_d, opp2D_d, w2D_d, cg_w_d, hocg_w_d, hocg_cx_d, hocg_cy_d, w_pert_d, psi_d, chi_d, teta_d, phi_d)
// 3D
#pragma acc declare create(c_norms3D_d, w_pert3D_d, psi3D_d, chi3D_d, teta3D_d, wIn_d, phi3D_d, cg_w3D_d, hocg_w3D_d, hocg_cx3D_d, hocg_cy3D_d, hocg_cz3D_d, hoc3D_d,velMomMap3D_d, momCollMtx3D_d, minInletCoordZ_d, maxInletCoordZ_d, height_d, c3D_d, cx3D_d, cy3D_d, cz3D_d, opp3D_d, w3D_d)

#endif

#endif
