.. MyLVGLWatch documentation master file, created by
   sphinx-quickstart on Fri Sep  9 16:56:25 2022.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to MyLVGLWatch's documentation!
=======================================

.. figure:: junto.jpg
   :alt: watch faces and states
   
   watch *sleeping* (leftmost), displaying time (center), in data transfer state (right) 

What is this?
-------------

This is a personal activity logger (PAL) built on a programmable wristwatch. 

The watch owner selects, through watch's touchscreen, what activity is starting. The selected activity, date and time of the activity are logged. The log can be seen on any device with a web browser and wifi connection. (Detailed information in `How to use the personal activity logger`).

It is a sort of DIY device (no warranties and some work to get it going 🙂 ).

How to use the personal activity logger
------------------------------------------

PAL more frequent state is screen off, counting time, waiting for the owner to touch its screen. It is, in some sense, *sleeping*. By touching the screen it turns on, displaying time.

In display time state, screen brightness can be improved by touching on time. Clicking *play* button inserts a *rodar* activity in the log. Clicking *pause* button inserts a *esperar* activity in the log. Other activities may be selected on the rolling menu at the right of the buttons. After selecting an activity, click on it to insert it in the log. There is a information bar, displaying date and battery charge, at the top of the screen. Touching it will switch the watch to the data transfer state.

In data transfer state there is a button to exit the screen (back to display time screen), a text (more precisely an IP address) and a button to toggle transfer mode on/off. With *transfer mode on*, PAL tries to connect do *NameOfNetworkTP* network with password *0123456789*. Upon connection, the watch's IP address is displayed as text. In this state, another device (e.g. desktop), connected to the same network, can access the activity log by typing ``IP/eventLog.csv``. The activity log can be copied (downloaded) to the desktop, opened in a spreadsheet and its contents can be studied.

Data transfer mode demands a lot from the battery. I recommend using it for as short as possible time, or plugging the watch to its charger.

About the meaning of the activity names
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The text (tag) for each activity entry in the log is embedded in the source-code. The tags are listed below.

List of activity tags (Brazilian Portuguese as in the initial release): Rodar (play button), Esperar (pause button), Caminhar, Oficina, Comer, Casa, Passear, Comprar, Exercitar, Descansar, Grupo.

List of activity tags (English translation): Ride (play button), Wait (pause button), Walk, Office, Eat, Home, Stroll, Shop, Exercise, Rest, Group.

Activity text is named *tag* because its meaning is not fixated. It is convenient that tag text relates to its meaning, though.

In a particular use a more precise meaning is possible:

.. list-table:: more precise meaning for the tags.
   :header-rows: 1
   * - tag (EN)
     - tag (pt-BR)
     - meaning
   * -  Ride (play button)
     - Wait (pause button) 
     - Walk 
     - Office 
     - Eat 
     - Home 
     - Stroll 
     - Shop 
     - Exercise 
     - Rest 
     - Group
   * - Rodar (play button)
     - Esperar (pause button) 
     - Caminhar 
     - Oficina 
     - Comer 
     - Casa 
     - Passear 
     - Comprar 
     - Exercitar 
     - Descansar 
     - Grupo
   * - Rodar (play button)
     - Esperar (pause button) 
     - Caminhar 
     - Oficina 
     - Comer 
     - Casa 
     - Passear 
     - Comprar 
     - Exercitar 
     - Descansar 
     - Grupo
     
   
How to get one
--------------

with minimum downloads and tools
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Get a TTGO T-Watch (tested with 2020 v.3) programmable watch;
- Get a desktop computer to program the watch;
- On the desktop, install ``esptool`` (this is the tool to send the program to the watch);
- On the desktop, download the files in ``bin`` (These are the personal activity annotator program in binary format);
- Connect the watch to the desktop with a USB data cable;
- Open the terminal, send the program with the command: ``python3 /home/fabio/.arduino15/packages/esp32/tools/esptool_py/3.3.0/esptool.py --chip esp32 --port /dev/ttyACM0 --baud 2000000 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 16MB 0x1000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.bootloader.bin 0x8000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.partitions.bin 0xe000 /home/fabio/.arduino15/packages/esp32/hardware/esp32/2.0.4/tools/partitions/boot_app0.bin 0x10000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.bin``

with development environment installation 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Get a TTGO T-Watch (tested with 2020 v.3) programmable watch;
- Get a desktop computer to program the watch;
- On the desktop, install ``Arduino IDE`` with support to ``ESP32`` board. (this is the tool to send the program to the watch);
   - some help with Arduino IDE: https://github.com/FNakano/CFA/tree/master/programas/arduinoIDE (Brazilian Portuguese)
   - some help with ESP32 support: https://github.com/FNakano/CFA/tree/master/componentes/controladores/ESP#configurar-arduinoide-para-programar-o-esp8266-ou-o-esp32 (Brazilian Portuguese) 
- On the desktop, download the files in ``src`` (These are the personal activity annotator program in binary format);
- Open the file ``MyLvglWatch20220910.ino`` with ``Arduino IDE``;
   - it probably will move the files to a new folder;
- Connect the watch to the desktop with a USB data cable;
- In tools menu select port (e.g. /dev/ttyACM0);
- In boards menu select ``TTGO T-Watch``;
- In tools menu select partition scheme: Large SPIFFS;
- In tools menu select ESP32 Sketch Data Upload;
   - this will send data (web pages) to your watch;
- Click on the arrow button;
   - this compiles the source-code and sends the binaries through USB.

Nuts and bolts
--------------

TBD

Source-code explained
^^^^^^^^^^^^^^^^^^^^^

TBD

How to improve the program
^^^^^^^^^^^^^^^^^^^^^^^^^^

TBD

My documentation project milestones
-----------------------------------

- Target zero: know what is this;
- Target 1: deploy the test explained above;
   - binaries and esptool (fastest if you don't have Arduino IDE installed and configured - just try this test case on your watch);
   - Arduino IDE, source-code download, compile and deploy (recommended if you want to program the watch);
- Target 2: learn what was done (and the underlying ideas);
- Target 3: learn how to expand it;
- Target 4: learn how to create the github repository and the RTD documentation

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

Instructions to build binaries: https://randomnerdtutorials.com/bin-binary-files-sketch-arduino-ide/

Folder containg binaries: `bin`

Send binaries to the watch: python3 /home/fabio/.arduino15/packages/esp32/tools/esptool_py/3.3.0/esptool.py --chip esp32 --port /dev/ttyACM0 --baud 2000000 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size 16MB 0x1000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.bootloader.bin 0x8000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.partitions.bin 0xe000 /home/fabio/.arduino15/packages/esp32/hardware/esp32/2.0.4/tools/partitions/boot_app0.bin 0x10000 /tmp/arduino_build_299108/MyLvglWatch-20220910.ino.bin 


The source-code repository is: https://github.com/FNakano/MyLVGLWatch

References to ReST: https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html#images, 

References to source-code documentation: https://doxygen.nl/manual/docblocks.html

References to emojis: https://gist.github.com/rxaviers/7360908, https://github.com/ikatyang/emoji-cheat-sheet, https://github.com/konveyor/pelorus/pull/320

emojipedia: https://emojipedia.org/

