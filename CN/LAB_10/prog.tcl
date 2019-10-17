set ns [new Simulator]

set nt [open simulate.nam w]
$ns namtrace-all $nt

set tr [open simulate.tr w]
$ns trace-all $tr

proc finish {} {
    global ns nt tr
    $ns flush-trace
    close $nt
    close $tr
    exec nam simulate.nam &
    exit 0
}

set S [$ns node]
set R [$ns node]
set D [$ns node]

$ns duplex-link $S $R 1mb 50ms DropTail
$ns duplex-link $R $D 100kb 5ms DropTail

$ns queue-limit $R $D 10

$ns duplex-link-op $R $D queuePos 0.5

set udp [new Agent/UDP]
$ns attach-agent $S $udp

set null [new Agent/Null]
$ns attach-agent $D $null

$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set rate_ 160kb
$cbr set random_ false

$ns at 0.2 "$cbr start"
$ns at 10.2 "$cbr stop"

$ns at 10.3 "finish"
$ns run

