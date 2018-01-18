# Caching Policy and Workload Analysis
### Platform
+ Ubuntu 16.04.3 LTS
### Dependency
+ g++
+ Python3
+ LaTex
    + To install: `sudo apt-get install texlive-full`
+ Pin 3.5
    + Download here [link](https://software.intel.com/en-us/articles/pin-a-binary-instrumentation-tool-downloads)
    + Add an environment variable `PIN_ROOT` in `/etc/environment`
    + Add an local command `pin`
        + `export PATH=$PATH":$HOME/bin"`
        + In `~/bin/`, create shortcut `pin`: `$PIN_ROOT/pin "$@"`
+ Perf
    + [link](http://www.brendangregg.com/perf.html)
    + Print page table [link](https://stackoverflow.com/questions/20069620/print-kernels-page-table-entries)
