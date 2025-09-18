/******************************************************************************
T2505_RFM95_Test4
*******************************************************************************

Required non-arduino Libraries:
  https://github.com/infrapale/T2409_atask

*******************************************************************************



-------------       --------------       --------------       --------------
| Remote    |       |  Remote    |       |  Base      |       |  Base      |
| Client    |       |  Client    |       |  Server    |       |  Server    |
| Master    |       |  RFM       |       |  RFM       |       |  Master    |
-------------       --------------       --------------       --------------
      |                   |                    |                    |
      |  remote_cmd       |                    |                    |
      |------------------>|                    |                    |
      |                   | remote_base_msg    |                    |
      |                   |------------------->|                    |
      |                   |                    |                    |
      |                   | base_remote_rpl    |                    |
      |                   |<------------------ |                    |
      
      |                   |                    |                    |
      |                   |                    | base_status        |
      |                   |                    |------------------->|
      |  remote_status    |                    |                    |
      |<------------------|                    |                    |
      |                   |                    |                    |
      |                   |                    |                    |
      |                   |                    |                    |

    remote_uart_send_msg:           <UR2B;from;target;radio;freq;pwr;sf;rnbr;bnbr>\n
    remote_to_base_radio_msg:       <RR2B;from;target;radio;freq;pwr;sf;rnbr;bnbr>
    base_to_remote_radio_reply:     <RB2R;from;target;radio;freq;pwr;sf;rnbr;bnbr>
    remote_status:                  <USTA;from;target;radio;freq;pwr;sf;rnbr;bnbr>\n
    base_status:                    <USTA;from;target;radio;freq;pwr;sf;rnbr;bnbr>\n
    set_parameter:                  <USET;pindex;value>
    get_parameter:                  <UGET;pindex;
    parameter_value:                <UVAL;pindex;value>
    
    msg_id  = 4 charcters
    from    = from node address 1..127
    target  = target node address  0..127
    radio   = LoRa  = 1 | RFM69 = 2
    freq    = 433 .. 868
    pwr     = power level:  5-20
    rssi    = last received rssi  -10 .. -140
    sf      = spreading factor
    rnbr    = remote send counter: 0-65000, incremented for each message sent by the remote
    bnbr    = base reply counter: 0-65000, incremented for each reply sent by the base
    pindx   = parameter index

  Examples:
    <RSND;1;2;L8;20;12;-88;1234;1001>\n   (UART Command)
    <RREP;1;2;L8;20;12;-101;1234;1001>     (Radio Message from server )

Send Radio Mesage:
<RSND;from;target;radio;pwr;rssi;sf;rnbr;bnbr>\n
<RSND;1;2;3;14;12;222;210>

Set Frequency:    <SFRQ;868>
Set Power Level:  <SPWR;pwr>, <SPWR;20>
Reset Radio:      <RRST;0>
Get Counter:      <CNTR;0>
Get Role:         <ROLE;0>
Set SF:           <S_SF;12>,  Spreading Factor values 6..12
    
Send Reply:
<RREP;from;target;radio;pwr;sf;rnbr;bnbr>\n
<RREP;1;2;3;14;12;33;444>





*******************************************************************************