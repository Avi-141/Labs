set ns [new Simulator]

set tr [open "out.tr" w]
$ns trace-all $tr


set nf [open "out.nam" w]
$ns namtrace-all $nf 

proc finish { } {
		global ns tr nf 
		$ns flush-trace
		close $nf
		exec nam out.nam &
		exit 0
		}

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 2Mb 4ms DropTail

 set cbr0 [new  Agent/CBR]
 $ns attach-agent $n0 $cbr0
 $cbr0 set packet_size_ 500
 $cbr0 set interval_ 0.005

 set null0 [new Agent/Null]
 $ns attach-agent $n1 $null0
 $ns connect $cbr0 $null0


$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"

#$ns at .1 "$ftp start" 
#$ns at 2.0 "$ftp stop"

$ns at 5.0 "finish"


$ns run 
