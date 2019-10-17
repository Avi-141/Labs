set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

set tr [open "out.tr" w]
$ns trace-all $tr


set ftr [open "out.nam" w]
$ns namtrace-all $ftr 

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 2Mb 4ms DropTail

#set tcp1 [new Agent/TCP]
#$ns attach-agent $n0 $tcp1
#$tcp1 set class_ 2


#set sink [new Agent/TCPSink]
#$ns attach-agent $n1 $sink 

#$ns connect $tcp1 $sink

#set ftp [new Application/FTP]
#$ftp attach-agent $tcp1
#$ftp set type_ FTP

set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
set null [new Agent/Null]
$ns attach-agent $n1 $null
$ns connect $udp $null
$udp set fid_ 2

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false


 #set cbr0 [new Agent/CBR]
 #$ns attach-agent $n0 $cbr0
 #$cbr0 set packetSize_ 500
 #$cbr set interval_ 0.005

# set null0 [new Agent/Null]
#$ns attach-agent $n1 $null0
# $ns connect $cbr0 $null0

proc finish { } {
		global ns tr ftr 
		$ns flush-trace
		close $tr
		close $ftr
		exec nam out.nam &
		exit
		}

#$ns at .1 "$ftp start" 
#$ns at 2.0 "$ftp stop"
$ns at .1 "$cbr start"
$ns at 2.0 "$cbr stop"

$ns at 3.1 "finish"


$ns run 
