balloon = CurrentComponent;

currentTranslation = 25;
incTranslation = 0.1;

function update()
	currentTranslation = currentTranslation + incTranslation;
	if ( currentTranslation < 25 or currentTranslation >= 50 ) then
		incTranslation = incTranslation * -1;
	end;
	
	balloon.translation.y = currentTranslation;
end