#ifndef VOLIMAGE_H
#define VOLIMAGE_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;
class VolImage{
	private: 
		
		int height , width, num_images;
		vector<u_char**> slices;
	    
	 public:
		VolImage();//constructor
		~VolImage();//destructor
		//read images
		bool readImages(string baseName);
		void diffmap(int sliceI, int sliceJ, string output_prefix);//difference between maps
		void extract(int sliceId, string output_prefix);//extract image
		int volImageSize(void);//size in bytes
		int volNumImage(void);//number of images
		
	
	
	};
#endif
