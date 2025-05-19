interface MicroUSBDevice {
    String getName();
}

interface LightningDevice {
    String getName();
}

class AndroidDevice implements MicroUSBDevice {
    private String name;
    public AndroidDevice(String name) { this.name = name; }
    public String getName() { return name; }
}

class AppleDevice implements LightningDevice {
    private String name;
    public AppleDevice(String name) { this.name = name; }
    public String getName() { return name; }
}

class USBCDevice {
    private String name;
    public USBCDevice(String name) { this.name = name; }
    public String getName() { return name; }
}

class UniversalCharger {
    public void charge(USBCDevice device) {
        System.out.println("Charging " + device.getName() + " with USB-C");
    }
}

class ChargerAdapter extends USBCDevice {
    public ChargerAdapter(MicroUSBDevice device) {
        super(device.getName() + " via Micro-USB using USB-C adapter");
    }

    public ChargerAdapter(LightningDevice device) {
        super(device.getName() + " via Lightning using USB-C adapter");
    }
}

public class AdapterDemo {
    public static void main(String[] args) {
        UniversalCharger charger = new UniversalCharger();
        charger.charge(new USBCDevice("Laptop"));
        charger.charge(new ChargerAdapter(new AndroidDevice("Samsung Galaxy")));
        charger.charge(new ChargerAdapter(new AppleDevice("iPhone")));
    }
}

