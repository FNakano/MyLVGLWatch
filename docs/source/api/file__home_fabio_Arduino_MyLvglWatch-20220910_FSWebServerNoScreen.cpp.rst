
.. _file__home_fabio_Arduino_MyLvglWatch-20220910_FSWebServerNoScreen.cpp:

File FSWebServerNoScreen.cpp
============================

|exhale_lsh| :ref:`Parent directory <dir__home_fabio_Arduino_MyLvglWatch-20220910>` (``/home/fabio/Arduino/MyLvglWatch-20220910``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS


.. contents:: Contents
   :local:
   :backlinks: none

Definition (``/home/fabio/Arduino/MyLvglWatch-20220910/FSWebServerNoScreen.cpp``)
---------------------------------------------------------------------------------


.. toctree::
   :maxdepth: 1

   program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_FSWebServerNoScreen.cpp.rst



Detailed Description
--------------------

It is useful to upload/browse/download/ files to the watch. This is achieved using a web server. This code is based on Arduino IDE, ESP32, FSWebServer. Functions were added to interface FSWebServer to other modules in the watch. Minor changes over Arduino IDE, ESP32, FSWebServer. Original copyright message preserved below.

FSWebServer - Example WebServer with FS backend for esp8266/esp32 Copyright (c) 2015 Hristo Gochkov. All rights reserved. This file is part of the WebServer library for Arduino environment.

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version. This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details. You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

upload the contents of the data folder with MkSPIFFS Tool ("ESP32 Sketch Data Upload" in Tools menu in Arduino IDE) or you can upload the contents of a folder if you CD in that folder and run the following command: for file in ``ls -A1``; do curl -F "file=@$PWD/$file" esp32fs.local/edit; done

access the sample web page at http://esp32fs.local edit the page by going to http://esp32fs.local/edit

Falta criar o header e arrumar as chamadas na tela. 




Includes
--------


- ``ESPmDNS.h``

- ``FFat.h``

- ``NetworkNoScreen.h`` (:ref:`file__home_fabio_Arduino_MyLvglWatch-20220910_NetworkNoScreen.h`)

- ``SPIFFS.h``

- ``WebServer.h``

- ``WiFi.h``

- ``WiFiClient.h``

- ``config.h`` (:ref:`file__home_fabio_Arduino_MyLvglWatch-20220910_config.h`)






Functions
---------


- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1ab85d2b44d50825cf75349dcf7681bf70`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a135df671bbc70b5f464cb5a0a18bf16d`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a761e6c07b34138806660f0a941b280f6`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1ac1311527864d9a4219f50d677608e538`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a8c77f65f0ebc6f33815c1b24e5698cf7`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a1266b17297c36cb097123920f0a089a9`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a5a374ae4e01508d13e7256d117695c49`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a0548bb0730eb6fb24d9d764ec31337c0`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a3ad222f20f56d154a7728c39310e6873`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a8afd16649ea8d46256f9bf48ac0b379c`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a48f3f185be3ea2d153c347a157b38d42`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1a0eb8be4b5aad5940f26990d4d28f1eca`

- :ref:`exhale_function_FSWebServerNoScreen_8cpp_1acd30b7f65cbd3d6ab18b624c0c102ee5`


Defines
-------


- :ref:`exhale_define_FSWebServerNoScreen_8cpp_1a8329fe5b96ea951b0d6342dab3c944fd`

- :ref:`exhale_define_FSWebServerNoScreen_8cpp_1aa426160a737ec3fec0e82834c37a59c8`

- :ref:`exhale_define_FSWebServerNoScreen_8cpp_1add35ecfc59bf9641224ba2ca471f2e4f`


Variables
---------


- :ref:`exhale_variable_FSWebServerNoScreen_8cpp_1a85a1845cd6671bcef69845032851013b`

- :ref:`exhale_variable_FSWebServerNoScreen_8cpp_1ae032e164f1daa754d6fbb79d59723931`

- :ref:`exhale_variable_FSWebServerNoScreen_8cpp_1a80a021ae6f2cb4467a17a0a4e2340fad`

