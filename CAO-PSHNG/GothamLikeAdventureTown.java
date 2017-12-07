import java.util.ArrayList;
public class GothamLikeAdventureTown{
	public GothamLikeAdventureTown(){
		String firstName[] = {"Vishal","Shahil","Kunal", "Sudarshan","Vikrant", "Ayush", "George","Kush", "Ayush (The other one)", "NA"};
		String lastName[] = {"Agarwal","Patel", "Amladi", "Seshadri","Singh", "Miller", "Anand", "Smith", "Ehrmantraut","NA"};
		String jobs[] = {"Unemployed/Canadian", "Memer", "YouTuber", "IT guy", "\"That\" guy", "Professional BTD5 player", "The guy who types the google autocompletes", "Ayush", "AP comp sci teacher", "Actor"};
		ArrayList<Person> dailyPlanetStreet= new ArrayList<Person>();
		boolean BG = true;
		boolean GG = true;
		for(int i = 0; i!=50;i++){
			if(i>47&&(BG||GG)){
				if(BG){
					dailyPlanetStreet.add(new BadGuy(    firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , "That one BadGuy...", jobs[(int)(Math.random()*10)], 100, 10, 10, "Evil powers", true, 7, "EVIL words"));
					BG=false;
				}else{
					dailyPlanetStreet.add(new GoodGuy(    firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , "That one Super hero...", jobs[(int)(Math.random()*10)], 100, 10, 10, "Generic Super Power", false, 7, "Words"));
					GG=false;
				}
			}else if (BG&&(int)(Math.random()*50) == 0){
					dailyPlanetStreet.add(new BadGuy(    firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , "That one BadGuy...", jobs[(int)(Math.random()*10)], 100, 10, 10, "Evil powers", true, 7, "EVIL words"));
					BG=false;
			}else if (GG&&(int)(Math.random()*50) == 0){
					dailyPlanetStreet.add(new GoodGuy(    firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , "That one Super hero...", jobs[(int)(Math.random()*10)], 100, 10, 10, "Generic Super Power", false, 7, "Words"));
					GG=false;
			}else{
				dailyPlanetStreet.add(new NormalGuy( firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , jobs[(int)(Math.random()*10)]));
			}
		}
		for(int i = 0; i!=dailyPlanetStreet.size();i++){
			System.out.println(dailyPlanetStreet.get(i));
		}
		for(int i = 0; i!=50;i++){
			System.out.println();
		}
		ArrayList<Person> safetyLand = new ArrayList<Person>();
		ArrayList<Person> unfortunaelyFatallyWounded= new ArrayList<Person>();

		ArrayList<Person> alive = dailyPlanetStreet;
		ArrayList<Person> dead = safetyLand;
		ArrayList<Person> safe = unfortunaelyFatallyWounded;
		while(alive.size()>2){
			for(int i = alive.size()-1; i!=0;i--){
				boolean someoneDied =true;
				if(alive.get(i) instanceof BadGuy){
					if(i!=0&&alive.get(i-1) instanceof NormalGuy){
						if(i<alive.size()-1 && alive.get(i+1) instanceof NormalGuy)
							if((Math.random()*2) == 0)
								dead.add(alive.remove(i-1));
							else
								dead.add(alive.remove(i+1));
						else
							dead.add(alive.remove(i-1));
					}else if(i<alive.size()-1 && alive.get(i+1) instanceof NormalGuy){
						dead.add(alive.remove(i+1));
					}else{
						someoneDied = false;
					}
					if(someoneDied){
						int indexOfBadGuy=0;
						for(int x = alive.size()-1; x!=0;x--)
							if(alive.get(x) instanceof BadGuy)
								indexOfBadGuy = x;
						System.out.println(dead.get(dead.size()-1).getName()+" Died...");
						System.out.println(alive.get(indexOfBadGuy).getName()+" says: "+((BadGuy)alive.get(indexOfBadGuy)).getEvilLaugh());
					}
				}
			}
			if(alive.size()>2){
				int savedPersonIndex;
				do{
					savedPersonIndex = (int)(Math.random()*alive.size());
				}while(!(alive.get(savedPersonIndex) instanceof NormalGuy));
				safe.add(alive.remove(savedPersonIndex));
				int couter = -1;
				do{
					couter++;
				}while(!(alive.get(couter) instanceof GoodGuy));
				System.out.println(safe.get(safe.size()-1).getName()+" has been saved!");
				System.out.println(alive.get(couter).getName()+" says: "+((GoodGuy)alive.get(couter)).getCatchPhrase());
				alive.add((int)(Math.random() * alive.size()), alive.remove(couter) );
			}
		}
		for(int i = 0; i!=50;i++){
			System.out.println();
		}
		for(int i = 0; i!=dailyPlanetStreet.size();i++){
			System.out.println(dailyPlanetStreet.get(i));
		}
	}
	public static void main(String[]args){
		GothamLikeAdventureTown app = new GothamLikeAdventureTown();
	}
}