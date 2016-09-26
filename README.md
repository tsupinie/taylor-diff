# Taylor
Taylor is a C library containing finite differencing routines

## Methods (Current and Future)
* [x] `diff1_2o_1d()` (1st derivative of _O(h<sup>2</sup>)_ error in 1 dimension)
* [x] `diff1_2o_2di()` (1st derivative of _O(h<sup>2</sup>)_ error in the _i_ direction of a 2D array; untested)
* [x] `diff1_2o_2dj()` (1st derivative of _O(h<sup>2</sup>)_ error in the _j_ direction of a 2D array; untested)
* [ ] `diff1_2o_3di()` (1st derivative of _O(h<sup>2</sup>)_ error in the _i_ direction of a 3D array)
* [ ] `diff1_2o_3dj()` (1st derivative of _O(h<sup>2</sup>)_ error in the _j_ direction of a 3D array)
* [ ] `diff1_2o_3dk()` (1st derivative of _O(h<sup>2</sup>)_ error in the _k_ direction of a 3D array)
* [ ] `diff1_2o_4di()` (1st derivative of _O(h<sup>2</sup>)_ error in the _i_ direction of a 4D array)
* [ ] `diff1_2o_4dj()` (1st derivative of _O(h<sup>2</sup>)_ error in the _j_ direction of a 4D array)
* [ ] `diff1_2o_4dk()` (1st derivative of _O(h<sup>2</sup>)_ error in the _k_ direction of a 4D array)
* [ ] `diff1_2o_4dl()` (1st derivative of _O(h<sup>2</sup>)_ error in the _l_ direction of a 4D array)

For more higher-order derivatives or methods with less error:
* [ ] `diff1_3o_[dim]()` (1st derivative or _O(h<sup>3</sup>)_ error)
* [ ] `diff1_4o_[dim]()` (1st derivative or _O(h<sup>4</sup>)_ error)
* [ ] `diff1_5o_[dim]()` (1st derivative or _O(h<sup>5</sup>)_ error)
* [ ] `diff2_4o_[dim]()` (2nd derivative of _O(h<sup>2</sup>)_ error)
