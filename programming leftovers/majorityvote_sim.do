##########################################################
#           Majority Vote .do file
#                                                                                             
#  Description:
#    An all-in-one do file for a majority vote circuit
#    that displays a functional simulation to the user.
#    Built for the introductory FPGA lab for EE110L.
#
#  Bryan Woolsey
#  Northern Arizona University
#  ModelSim-Altera v6.5e
#  01 Oct 2010
##########################################################

#Change directory and create work library
cd I:/ee110/fpgaintro/simulation/modelsim
vlib work

#Compile
vcom -reportprogress 300 -work work I:/ee110/fpgaintro/simulation/modelsim/majorityvote.vho

#Start functional simulation
vsim work.majorityvote(structure)

#Add required waves & dividers
add wave -noupdate -divider -height 32 Inputs
add wave \
{sim:/majorityvote/a } \
{sim:/majorityvote/b } \
{sim:/majorityvote/c } 
add wave -noupdate -divider -height 32 Output
add wave -color Red {sim:/majorityvote/y } 

#Initial input state
force a 0
force b 0
force c 0

#Timing, counts from 000 to 111
force c 1 50ns, 0 100ns -r 100ns
force b 1 100ns, 0 200ns -r 200ns
force a 1 200ns, 0 400ns -r 400ns
run 400ns
