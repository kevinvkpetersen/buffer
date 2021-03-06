Producers and Consumers
============

Implementation of a synchronous circular buffer. Producers and consumers run simultaneously in a number of threads provided by the user.

Inspiration
------------

From EECE 315, Operating and File Systems.

Installation
------------

Windows (Visual Studio):

    cd {solution destination}
    git clone https://github.com/kevinvkpetersen/buffer.git

In Visual Studio, go to File > New > Project... and select a Visual C++ Empty Project. Enter 'buffer' in the Name: field and ensure 'Create directory for solution' is unchecked. Right-click on buffer project, go to Add > Existing Item... and select the project's .c and .h files. To build project, go to Build > Build Solution; buffer.exe will be in Debug folder.

Ubuntu 12.04 or Mac OS X:

	git clone https://github.com/kevinvkpetersen/buffer.git
	cd buffer
	make all 

Usage
------------

Run from the Command Prompt with execution time, number of producers and number of consumers. For example, on Windows:

    buffer.exe 5 4 3

Or, on Ubuntu or Mac:

	./buffer 5 4 3

To get Visual Studio to send command line arguments, right-click on the buffer project and select Properties. Under Configuration Properties > Debugging, click in the second column in the Command Arguments row and enter the execution time, number of producer threads, and number of consumer threads.

Performance
------------

Performs as expected with very little overhead.

Copyright 2014, Kevin Petersen. All rights reserved.