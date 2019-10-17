set ns [new Simulator]

set tr [open "out1.tr" w]
$ns trace-all $tr

set nf [ open "out1.nam" w]
$ns namtrace-all $nf

set s [$ns node]
set r [$ns node]
set d [$ns node]

$ns duplex-link $s $r 12mb 1msec DropTail
$ns duplex-link $r $d 12mb 1msec DropTail

$ns queue-limit $r $d 10

$ns duplex-link-op $r $d queuePos 1.5

set udp1 [new Agent/UDP]
$ns attach-agent $s $udp1
set null1 [new Agent/null1]
$ns attach-agent $d $null1
$ns connect $udp1 $null1


set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1


proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam out1.nam & 
	exit 0
} 

$ns at 0.1 "$cbr1 start"
$ns at 10.0 "$cbr1 start"
$ns at 10.2 "finish"


$ns run
