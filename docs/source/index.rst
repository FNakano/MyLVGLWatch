.. MyLVGLWatch documentation master file, created by
   sphinx-quickstart on Fri Sep  9 16:56:25 2022.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to MyLVGLWatch's documentation!
=======================================

.. image:: junto.jpg

This is a personal activity annotator built on a programmable wristwatch. 

The watch owner selects, through watch's touchscreen, what activity is starting. The selected activity, date and time of the activity is recorded. The record can be seen on any device with a web browser. (Detailed information in `How to use the personal activity annotator`).

It is a sort of DIY device (no warranties and some work to get it going :smile ).

How to get one
--------------

- Get a TTGO T-Watch (tested with 2020 v.3) programmable watch;
- Get a desktop computer to program the watch;
- On the desktop, install ``esptool`` (this is the tool to send the program to the watch);
- On the desktop, download the files in ``src`` (These are the personal activity annotator program in binary format);
- Connect the watch to the desktop with a USB data cable;
- Open the terminal, send the program with the command: ``python3 /home/fabio/.arduino15/packages/esp32/tools/esptool_py/3.3.0/esptool.py --chip esp32 --port /dev/ttyACM0 --baud 2000000 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 16MB 0x1000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.bootloader.bin 0x8000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.partitions.bin 0xe000 /home/fabio/.arduino15/packages/esp32/hardware/esp32/2.0.4/tools/partitions/boot_app0.bin 0x10000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.bin``

My documentation project milestones
-----------------------------------

- Target zero: know what is this;
- Target 1: deploy the test explained above;
   - binaries and esptool (fastest if you don't have Arduino IDE installed and configured - just try this test case on your watch);
   - Arduino IDE, source-code download, compile and deploy (recommended if you want to program the watch);
- Target 2: learn what was done (and the underlying ideas);
- Target 3: learn how to expand it;
- Target 4: learn how to create the github repository and the RTD documentation


Instructions to build binaries: https://randomnerdtutorials.com/bin-binary-files-sketch-arduino-ide/

Folder containg binaries: `bin`

Send binaries to the watch: python3 /home/fabio/.arduino15/packages/esp32/tools/esptool_py/3.3.0/esptool.py --chip esp32 --port /dev/ttyACM0 --baud 2000000 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 16MB 0x1000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.bootloader.bin 0x8000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.partitions.bin 0xe000 /home/fabio/.arduino15/packages/esp32/hardware/esp32/2.0.4/tools/partitions/boot_app0.bin 0x10000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.bin 


The source-code repository is: https://github.com/FNakano/MyLVGLWatch

References to ReST: https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html#images, 

References to source-code documentation: https://doxygen.nl/manual/docblocks.html

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   about
   api/library_root


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
