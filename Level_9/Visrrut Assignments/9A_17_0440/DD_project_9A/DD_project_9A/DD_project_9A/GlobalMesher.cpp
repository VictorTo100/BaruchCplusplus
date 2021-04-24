
/*Definition of the global mesher
* It create point across  point at a time
*/
#include"GlobalMesher.h"
using namespace std;

std::vector<double> GenerateMesh(const double& mesh_size, const double& start_mesh, const double& end_mesh)
{
	/*Divided the difference between start and end
	*/
	int size = ((end_mesh - start_mesh) / mesh_size)+1;

	std::vector<double> result(size);
	/*Declare result for storing
	*/
	result[0] = start_mesh;

	for (unsigned int j = 1; j < result.size(); j++)
	{
		result[j] = result[j - 1] + mesh_size;
	}
	return result;
}