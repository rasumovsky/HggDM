#!/bin/bash

if [[ $# -lt 5 ]]; then
    echo "USAGE: CL_jobfile.sh <jobname> <input_file> <exe_name> <signal> <joboption>"
    
else
    jobname=$1
    input_file=$2
    exe_name=$3
    signal=$4
    joboption=$6

    date
    echo
    
    echo $jobname $input_file $exe_name $signal
    
    out="${jobname}_${signal}"
    output_dir="/afs/cern.ch/user/a/ahard/work_directory/files_HggDM/FullAnalysis/${jobname}/DMMuLimit"
    
    # setup ROOT:
    source /afs/cern.ch/sw/lcg/contrib/gcc/4.6/x86_64-slc6/setup.sh 
    source /afs/cern.ch/sw/lcg/app/releases/ROOT/5.34.09/x86_64-slc6-gcc46-opt/root/bin/thisroot.sh
    
    export PATH=$ROOTSYS/bin:$PATH
    export LD_LIBRARY_PATH=$ROOTSYS/lib
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/afs/cern.ch/project/eos/installation/pro/lib64/
    
    # setup GCC:
    source  /afs/cern.ch/sw/lcg/contrib/gcc/4.6/x86_64-slc6-gcc46-opt/setup.sh /afs/cern.ch/sw/lcg/contrib
    
    # Make output directories:    
    mkdir -vp ${output_dir}/single_files
    mkdir -vp ${output_dir}/log
    mkdir -vp ${output_dir}/err
    
####################
# copying necessary inputs into working dir
    cp $input_file .
    tar zxvf Cocoon.tar

####################    
# Go!
    echo "Printing directory contents before running."
    ls
    
    ./bin/${exe_name} ${jobname} ${signal} ${joboption} 1> ${out}.log 2>${out}.err;
    
    mv *.log ${output_dir}/log
    mv *.err ${output_dir}/err
    rm * -rf
    
####################
# End
    echo "----------All done------------"
    date
    
fi
