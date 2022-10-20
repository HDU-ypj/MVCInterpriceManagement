#include <fstream>
#include "manager_mode_impl.h"
#include "manager_ctrl_impl.h"

void ManagerModeImpl::load(vector<Manager>& mgrArr)
{
	ifstream ifs(DATA_MGR_PATH,ios::in|ios::binary);
	if(!ifs)	return;
	while(true)
	{
		Manager mgr;
		ifs.read((char*)&mgr,sizeof(mgr));
		if(ifs.fail())	break;
		mgrArr.push_back(mgr);
	}
	ifs.close();
}

void ManagerModeImpl::save(const vector<Manager>& mgrArr)
{
	ofstream ofs(DATA_MGR_PATH,ios::out|ios::binary);
	if(!ofs)	return;
	for(unsigned int i=0; i<mgrArr.size(); i++)
	{
		ofs.write((char*)&mgrArr[i],sizeof(mgrArr[i]));
	}
	ofs.close();
}
