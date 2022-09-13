A LVGL + TTGO T-Watch test with documentation
=============================================

#. Started by cloning RTD template: https://docs.readthedocs.io/en/stable/tutorial/ into github repository;
#. Clone github repository to local directory;
#. In the local copy: adapt ``conf.py`` (changed project name, author, ...);
#. In the local copy: Remove ``lumache.py``;
#. In the local copy: create folder ``src``, containing test source code;
#. In the local copy: copy documentation (generated using ``exhale``, ``breathe``, ``doxygen`` and ``sphinx``) into ``docs/source``;
   - replaced ``index.rst`` and created/copied folder ``api``;
#. Add, commit, push;
#. Deploy to RTD;

Result: The file hierarchy is accessed in https://mylvglwatch.readthedocs.io/en/latest/api/library_root.html# but the documentation embedded as comments in the source-code is not shown. 

#. Change ``conf.py`` to run `breathe`;
#. add folder ``_doxygen`` and its contents;

Result: RTD compilation failed. It did not find ``breathe``. Googled to a solution. Found: https://github.com/michaeljones/breathe/issues/89 and https://github.com/Cruel/readthedocs-breathe/tree/master/docs. Noticed that I missed file ``requirements.txt``. Included it to my repo. It compiled and the source-code embedded documentation appeared.
