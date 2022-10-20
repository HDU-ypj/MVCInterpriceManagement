#include <fstream>
#include "service_mode_impl.h"

void ServiceModeImpl::load(vector<Department>& dep)
{
	ifstream ifs(DATA_SRV_PATH);
	if(!ifs)	return;
	int size_dep=0;
	Department dep_temp;
	ifs >> size_dep;

	for(int i=0; i<size_dep; i++)
	{
		dep_temp.empArr.clear();
		ifs >> dep_temp;
		dep.push_back(dep_temp);
	}
	ifs.close();
}
void ServiceModeImpl::save(const vector<Department>& dep)
{
	ofstream ofs(DATA_SRV_PATH);
	if(!ofs)	return;

	ofs <<dep.size() << endl;
	for(unsigned int i=0; i<dep.size(); i++)
	{
		ofs << dep[i] << endl;
	}
	ofs.close();
}
