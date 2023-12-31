#pragma once

#include <iostream>
#include <sstream>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <inttypes.h>

#include "utils.hpp"

class DirectoryListing {
	public:
		DirectoryListing();
		DirectoryListing( const DirectoryListing &conf );
		~DirectoryListing();
		DirectoryListing & operator = (const DirectoryListing &conf);
		std::string	create_listing_html( std::string dir_path, std::string show_path );


	private:

		std::string		_create_head( std::string path );
		std::string		_create_parent_dir( void );
		std::string		_create_all_listings( std::string dir_path );
		std::string		_create_one_listing( struct dirent* entry, std::string path );
		std::string		_last_modified( std::string path );
		std::string		_size( std::string path );
		std::string		_end( void );
};
