////////////////////////////////////////////////////////////////////////
// Include file for RGBD utility functions
////////////////////////////////////////////////////////////////////////

#ifndef __RGBD__UTIL__H__
#define __RGBD__UTIL__H__



////////////////////////////////////////////////////////////////////////
// Namespace
////////////////////////////////////////////////////////////////////////

namespace gaps {

  

////////////////////////////////////////////////////////////////////////
// High-level Image Channel Creation Functions
////////////////////////////////////////////////////////////////////////

int RGBDCreatePositionChannels(RGBDImage *image,
  R2Grid& output_px_image, R2Grid& output_py_image, R2Grid& output_pz_image,
  RNBoolean world_coordinates = TRUE);

int RGBDCreateNormalChannels(RGBDImage *image,
  R2Grid& output_nx_image, R2Grid& output_ny_image, R2Grid& output_nz_image,
  RNLength neighborhood_world_radius = 0.1, int neighborhood_pixel_radius = 2, RNBoolean neighborhood_search = TRUE,
  RNBoolean world_coordinates = TRUE);

int RGBDCreateTangentChannels(RGBDImage *image,
  R2Grid& output_nx_image, R2Grid& output_ny_image, R2Grid& output_nz_image,
  R2Grid& output_tx_image, R2Grid& output_ty_image, R2Grid& output_tz_image,
  R2Grid& output_r1_image, R2Grid& output_r2_image,
  RNLength neighborhood_world_radius = 0.1, int neighborhood_pixel_radius = 2, RNBoolean neighborhood_search = TRUE,
  RNBoolean world_coordinates = TRUE);

int RGBDCreateBoundaryChannel(RGBDImage *image,
  R2Grid& output_boundary_image,
  RNScalar depth_threshold = 0.1);



////////////////////////////////////////////////////////////////////////
// Mid-level Image Channel Creation Functions
////////////////////////////////////////////////////////////////////////

int RGBDCreatePositionChannels(
  const R2Grid& input_undistorted_depth_image,
  R2Grid& output_px_image, R2Grid& output_py_image, R2Grid& output_pz_image,
  const R3Matrix& intrinsics_matrix, const R4Matrix& camera_to_world_matrix);

int RGBDCreateNormalChannels(const R2Grid& input_depth_image, 
  const R2Grid& input_px_image, const R2Grid& input_py_image, const R2Grid& input_pz_image,
  const R2Grid& input_boundary_image,
  R2Grid& output_nx_image, R2Grid& output_ny_image, R2Grid& output_nz_image, R2Grid& output_radius_image,
  const R3Point& viewpoint, const R3Vector& towards, const R3Vector& up,
  RNLength neighborhood_world_radius = 0.1, int neighborhood_pixel_radius = 2, RNBoolean neighborhood_search = TRUE);

int RGBDCreateTangentChannels(const R2Grid& input_depth_image, 
  const R2Grid& input_px_image, const R2Grid& input_py_image, const R2Grid& input_pz_image,
  const R2Grid& input_boundary_image,
  R2Grid& output_nx_image, R2Grid& output_ny_image, R2Grid& output_nz_image,
  R2Grid& output_tx_image, R2Grid& output_ty_image, R2Grid& output_tz_image,
  R2Grid& output_r1_image, R2Grid& output_r2_image,
  const R3Point& viewpoint, const R3Vector& towards, const R3Vector& up,
  RNLength neighborhood_world_radius = 0.1, int neighborhood_pixel_radius = 2, RNBoolean neighborhood_search = TRUE);

int RGBDCreateBoundaryChannel(
  const R2Grid& input_depth_image, R2Grid& output_boundary_image,
  RNScalar depth_threshold = 0.1);



////////////////////////////////////////////////////////////////////////
// Low-level Undistortion Functions
////////////////////////////////////////////////////////////////////////

int RGBDCreateUndistortedColorImage(
  const R2Grid& input_distorted_color_image,
  R2Grid& output_undistorted_color_image,
  const RGBDCamera& distorted_camera, const RGBDCamera& undistorted_camera);

int RGBDCreateUndistortedDepthImage(
   const R2Grid& input_distorted_depth_image,
   R2Grid& output_undistorted_depth_image,
   const RGBDCamera& distorted_camera, RGBDCamera& undistorted_camera);



////////////////////////////////////////////////////////////////////////
// Low-level Resampling Functions
////////////////////////////////////////////////////////////////////////

int RGBDResampleDepthImage(R2Grid& image, R3Matrix& intrinsics_matrix, int xres, int yres);

int RGBDResampleColorImage(R2Image& image, R3Matrix& intrinsics_matrix, int xres, int yres);



////////////////////////////////////////////////////////////////////////
// Alignment Functions
////////////////////////////////////////////////////////////////////////

#if 0
R3Affine RGBDAlignmentTransformation(RGBDImage *image0, RGBDImage *image1, 
  RNLength start_max_distance = 0.25, RNLength end_max_distance = 0.05, int max_iterations = 16);
#endif



// End namespace
}


// End include guard
#endif
  
