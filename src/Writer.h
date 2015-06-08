/**
 * Author: rodrigo
 * 2015
 */
#pragma once

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Triangle.h"

using namespace std;
using namespace pcl;
using namespace Eigen;

#define OUTPUT_FOLDER		"./output/"
#define SPHERE_EXTENSION	".sph"
#define POLYGON_EXTENSION	".off"

#define SSTR(x)			dynamic_cast< std::stringstream &>((std::stringstream() << std::dec << std::setfill('0') << std::setw(5) << x)).str()

class Writer
{
public:
	static void writeCircumscribedSphere(const string &_filename, const Vector3f &_center, const double _radius, const Triangle &_triangle, const PointCloud<PointNormal>::Ptr &_neighborhood, const bool _addSequential = false);
	static void writeMesh(const string &_filename, const PointCloud<PointNormal>::Ptr &_cloud, const vector<TrianglePtr> &_meshData, const bool _addSequential = false);
	static void writeMesh(const string &_filename, const vector<TrianglePtr> &_meshData, const bool _addSequential = false);
	static void writeMesh(const string &_filename, const PointCloud<PointNormal>::Ptr &_cloud, const vector<TrianglePtr> &_meshData, const TrianglePtr &_seed, const bool _addSequential = false);
	static void writeMesh(const string &_filename, const PointCloud<PointNormal>::Ptr &_cloud, const vector<TrianglePtr> &_meshData, const EdgePtr &_boundary, const bool _addSequential = false);
	static void writeTriangle(const string &_filename, const Triangle &_triangle);

private:
	Writer();
	~Writer();

	static void generateMesh(const vector<TrianglePtr> &_meshData, ofstream &_output);
	static void generateCloud(const PointCloud<PointNormal>::Ptr &_cloud, ofstream &_output);
	static void generateSphere(const Vector3f &_center, const double _radius, ofstream &_output);
	static void generateTriangle(const Triangle &_triangle, ofstream &_output);
	static void generateTriangleFace(const TrianglePtr &_triangle, ofstream &_output);
	static void generateNormals(const PointCloud<PointNormal>::Ptr &_cloud, ofstream &_output);
	static void generateEdge(const EdgePtr &_boundary, ofstream &_output);

	static inline string generateName(const string &_name, const string &_extension, bool _addSequential = false)
	{
		static int sequential = 0;

		string name = OUTPUT_FOLDER;
		if (_addSequential)
		{
			name += SSTR(sequential++)+ "_";
		}
		name += _name + _extension;

		return name;
	}
};
