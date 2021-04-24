
#include"GlobalMesher.h"
using namespace std;

std::vector<double> GenerateMesh(const double& mesh_size, const double& start_mesh, const double& end_mesh)
{
	int size = ((end_mesh - start_mesh) / mesh_size)+1;

	std::vector<double> result(size);
	result[0] = start_mesh;

	for (unsigned int j = 1; j < result.size(); j++)
	{
		result[j] = result[j - 1] + mesh_size;
	}
	return result;
}