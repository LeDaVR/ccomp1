#include "terreno.h"

Terreno::Terreno(int _cubelen){
	cubelen=_cubelen;
	float x=0.0f,y=0.0f,z=0.0f;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			float _x=x,_y=y;
			for(int k=0;k<6;k++){
				if(k==1)
					_x+=80.0f;
				if(k==2)
					_y+=80.0f;
				if(k==3){
					_x-=80.0f;
					_y-=80.0f;
				}
				if(k==4)
					_y+=80.0f;
				if(k==5)
					_x+=80.0f;
				vector.push_back(_x);
				vector.push_back(_y);
				vector.push_back(z);
			}
			x+=80.0f;
		}
		x=0.0f;
		y+=80.0f;
	}

	for(int i=0;i<vector.size();i++){
		vertices.push_back(vector[i]);
	}
	for(unsigned int i=0;i<vertices.getSize()/3;i++){
		indices.push_back(i);
	}
		
}		
