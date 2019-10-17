set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Read
set tr [open "out2.tr" w]
$ns trace-all $tr

set nf [open "out2.nam" w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n1 2Mb 20msec DropTail
$ns duplex-link $n2 $n3 1Mb 10msec DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
#$ns make-lan "$n0 $n1 $n2 $n3" 1Mb 40ms LL Queue/DropTail Mac/802_3

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink
set tcp1 [new Agent/TCP]
$ns attach-agent $n2 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n3 $sink1

$ns connect $tcp $sink
$ns connect $tcp1 $sink1


set ftp [new Application/FTP]
$ftp attach-agent $tcp
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1

proc finish {} {
	global ns tr nf 
	$ns flush-trace
	close $tr
	close $nf 
	exec nam out2.nam &
	exit
}

$ns at .1 "$ftp start"
$ns at .2 "$ftp1 start"
$ns at 3.0 "$ftp stop"
$ns at 3.1 "$ftp1 stop"


$ns at 3.2 "finish"
