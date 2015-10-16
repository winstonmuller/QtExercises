Read some xml using the SAX parsing method. This merely shows how to implement the handler class, and is a nice sample for future, more in depth xml projects.

Using a SAX style parser, the parser will call events on the handler as they occur. The handler class the responds to those events.

Currently, my handler spits out the content into a textbox on screen. This is done via a pointer to the UI element being passed to the handler class, a quick but dirty solution to getting the data to the screen.

samplefile.xml thanks to ezust & ezust.