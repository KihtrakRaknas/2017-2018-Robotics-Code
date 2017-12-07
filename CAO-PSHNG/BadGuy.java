public class BadGuy extends SuperHero{
	private String evilLaugh;
	public BadGuy(String name, String heroName, String job, int hitPoint, int maxDamage, int defenseAbility, String superPower,boolean cape,int powerLevel,String evilLaugh){
		super(name,heroName,job,hitPoint,maxDamage,defenseAbility,superPower,cape,powerLevel);
		this.evilLaugh = evilLaugh;
	}
	public String getEvilLaugh(){
		return evilLaugh;
	}
	public String toString(){
		return super.toString()+"\tEvil Laugh: "+evilLaugh;
	}
}