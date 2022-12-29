/*
  TODO:  Add filename, author, date, purpose
 */


#ifndef _POLYGON_H
#define _POLYGON_H

#include "vertexSet.h"


class Polygon : public VertexSet {
	
	private: 
		// Private data
	  double normal[ 3 ];
	    
	    // Private methods
		void calcNormal( ) ;
		void calcVector( const Vertex & start, const Vertex & finish, double result[ 3 ] ) const;
		void cross( const double vec1[ 3 ], const double vec2[ 3 ], double result[ 3 ] ) const;
		double dot( const double vec1[ 3 ], const double vec2[ 3 ] ) const;
	    
	public: 
	    
	    // Constructors and destructor
		Polygon( );
		Polygon( int initialCapacity );
		~Polygon( );
	    
		virtual bool addVertex( const Vertex & vertex );
		virtual bool addVertex(  Vertex * vertexPtr );
		bool isCoplanar( const Vertex & vertex ) const;
		int results(){return nVertices;}
		void PolygonResults();
};

// TODO:  Add a means of printing Polygons, either as class methods or by operator <<

#endif //_POLYGON_H