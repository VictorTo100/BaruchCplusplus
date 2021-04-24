/*Author: Vishrut Talekar; Nov 2020
*/

/*Declaration of a global mesher function to create a Mesh of option parameters
*/
#ifndef GlobalMesher_H
#define GlobalMesher_H

#include<vector>

std::vector<double> GenerateMesh(const double& mesh_size, const double& start_mesh, const double& end_mesh);

#endif
