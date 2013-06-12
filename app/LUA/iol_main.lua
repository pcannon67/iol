#!/usr/bin/lua

require("rfsm")
require("yarp")

require("iol_funcs")

yarp.Network()

-------
shouldExit = false

-- initilization
ispeak_port = yarp.BufferedPortBottle()
speechRecog_port = yarp.Port()
iol_port = yarp.Port()

-- defining objects and actions vocabularies
objects = {"octopus", "lego", "toy", "ladybug", "turtle", "cat"}
actions = {"{point at}", "{what is this}"}

-- defining speech grammar for Menu
grammar = "Return to home position | Calibrate on table | Where is the #Object | Take the #Object | See you soon  | I will teach you a new object | "
	    .."Touch the #Object | Push the #Object | Let me show you how to reach the #Object with your right arm | Let me show you how to reach the #Object with your left arm | "
        .."Forget #Object | Forget all objects | Execute a plan | What is this | Explore the #Object "

-- defining speech grammar for Reward
grammar_reward = "Yes you are | No here it is | Skip it"

-- load state machine model and initalize it
fsm_model = rfsm.load("./iol_root_fsm.lua")
fsm = rfsm.init(fsm_model)
rfsm.run(fsm)


repeat
    rfsm.run(fsm)
    yarp.Time_delay(0.1)
until shouldExit ~= false

print("finishing")
-- Deinitialize yarp network
yarp.Network_fini()