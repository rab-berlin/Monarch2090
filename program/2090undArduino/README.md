Der Arduino möchte seine digitalen Ausgänge maximal mit 40 mA belastet sehen, typischerweise auch nur mit 20 mA. Die Eingänge des Microtronic haben jeweils 100 Ohm gegen GND. Das würde bei 5V dann aber 50 mA Strom fließen lassen. Wahrscheinlich auch verkraftbar für den Arduino, aber um auf der ganz sicheren Seite zu sein: 1 kOhm-Widerstände vor den Eingängen!

Wenn du mutig bist, kannst du die Stromversorung für den Arduino (+5V) vom 2090 abzweigen. Das spart ein Netzteil. Dazu müsstest du den richtigen Pin am Verbindungssockel zum 2095 anzapfen... mehr verrate ich nicht.
