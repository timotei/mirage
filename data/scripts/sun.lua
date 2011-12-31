sun = CurrentComponent;

currentRotation = 0;

function update()
	currentRotation = currentRotation + 0.5;
	if ( currentRotation >= 360 ) then
		currentRotation = currentRotation - 360;
	end;
	
	sun.rotation.y = currentRotation;
end